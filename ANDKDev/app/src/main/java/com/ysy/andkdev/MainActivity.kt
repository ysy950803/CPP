package com.ysy.andkdev

import android.annotation.SuppressLint
import android.content.Context
import android.media.AudioManager
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

@SuppressLint("SetTextI18n")
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = "${stringFromJNI(101, "321")}\n" + "${sumArrayFromJNI(intArrayOf(1, 2, 3))}"

        val aM = getSystemService(Context.AUDIO_SERVICE) as AudioManager
        val infos = aM.getDevices(AudioManager.GET_DEVICES_ALL)
        Log.e("TEST-1", infos.toList().toString())
        for (i in infos) {
            Log.e("TEST-1", "${i.productName} ${i.type} ${i.id} \n")
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(endI: Int, str: String): String

    private external fun sumArrayFromJNI(arr: IntArray): Int

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("test_native")
            System.loadLibrary("test_nn")
        }
    }
}
