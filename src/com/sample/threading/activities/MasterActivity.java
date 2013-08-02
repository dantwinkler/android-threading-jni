package com.sample.threading.activities;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.sample.threading.R;

public class MasterActivity extends Activity {

	public static String CLASSNAME = MasterActivity.class.getSimpleName();

	Button start;
	
	EditText results;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		init();

		setContentView(R.layout.master);
		
		start = (Button) findViewById(R.id.startThread);

		results = (EditText) findViewById(R.id.results);
		
		start.setOnClickListener( new View.OnClickListener() {
			public void onClick(View v) {
				startThread();
			}
		});
	}

	@Override
	protected void onPause() {
		super.onPause();
	}

	@Override
	protected void onResume() {
		super.onResume();
	}

	@Override
	protected void onStop() {
		super.onStop();
	}
	
	static
	{
		try {
			System.loadLibrary("threadingjnilib");
		} catch(UnsatisfiedLinkError ule) {
			System.out.println("Unable to load library!");
			System.out.println(ule.getMessage());
		}

	}

	public native void init();
	
	public native void startThread();
	
	synchronized public void logMessage(final String strMessage) {
		new Handler(getMainLooper()).post(new Runnable() {
	        @Override
	        public void run() {
	    		results.append(strMessage);
	        }
		});
		
	}
}
