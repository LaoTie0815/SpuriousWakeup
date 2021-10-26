package com.sensetime.testucproblem;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import io.reactivex.Observable;
import io.reactivex.ObservableOnSubscribe;
import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.schedulers.Schedulers;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());
        init();
    }


    @SuppressLint("CheckResult")
    public void testPing(View v){
        Observable.create((ObservableOnSubscribe<String>) emitter -> {

                ping();
            emitter.onNext("mtcReceiver");
        }).subscribeOn(Schedulers.single()).observeOn(AndroidSchedulers.mainThread())
                .subscribe(s -> {
//                    mtcCallback.onResult(s.getMtcCode(), s.getResult());
                });
    }

    public void notify(View v){
        notifyThread();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String init();
    public native String ping();
    public native String notifyThread();
}