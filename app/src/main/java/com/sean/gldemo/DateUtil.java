package com.sean.gldemo;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Locale;

/**
 * Utility class to display calendar dates
 */
class DateUtil {

    /**
     * Method used to return string of human readable date of current device time
     */
    String getFormattedDate() {
        SimpleDateFormat formatter =
              new SimpleDateFormat("EEE, MMM d, yyyy", Locale.getDefault());

        //Create a calendar object that will convert date and time value in milliseconds to date.
        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(System.currentTimeMillis());
        return "Native call to non-static Java date method:\nToday is "
              + formatter.format(calendar.getTime());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native String dateFromJNI();
}
