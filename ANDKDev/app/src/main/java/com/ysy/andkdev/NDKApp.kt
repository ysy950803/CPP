package com.ysy.andkdev

import android.app.Activity
import android.app.Application
import android.os.Bundle
import android.util.Log

class NDKApp : Application() {

    private var mSwitchCount : Int = 0

    override fun onCreate() {
        super.onCreate()
        registerActivityLifecycleCallbacks(object : ActivityLifecycleCallbacks {
            override fun onActivityCreated(activity: Activity?, savedInstanceState: Bundle?) {
                Log.d("TEST-1", "onActivityCreated $activity")
            }

            override fun onActivityStarted(activity: Activity?) {
                Log.d("TEST-1", "onActivityStarted $activity")
                if (mSwitchCount == 0) {
                    Log.w("TEST-1", "to front")
                }
                ++mSwitchCount
            }

            override fun onActivityResumed(activity: Activity?) {
                Log.d("TEST-1", "onActivityResumed $activity")
            }

            override fun onActivityPaused(activity: Activity?) {
                Log.d("TEST-1", "onActivityPaused $activity")
            }

            override fun onActivityStopped(activity: Activity?) {
                Log.d("TEST-1", "onActivityStopped $activity")
                --mSwitchCount
                if (mSwitchCount == 0) {
                    Log.w("TEST-1", "to back")
                }
            }

            override fun onActivitySaveInstanceState(activity: Activity?, outState: Bundle?) {
                Log.d("TEST-1", "onActivitySaveInstanceState $activity")
            }

            override fun onActivityDestroyed(activity: Activity?) {
                Log.d("TEST-1", "onActivityDestroyed $activity")
            }
        })
    }
}
