package com.hankyojeong.sampleapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView)findViewById(R.id.hello_textview);

        tv.setText(stringFromJNI());
    }

    /*
    A native method that is implemented by the 'hello-jni' native library
     */
    public native String stringFromJNI();

    /*
    This is used to load the 'hello-jni' library on application startup
     */
    static {
        System.loadLibrary("hello-jni");
    }
}
