android-threading-jni
=====================

Sample applications which uses JNI, boost and threading (Java &lt;-> C/C++).

ISSUE: Creating a second task seems to blow up in side of the boost TLS (thread local storage) code.  Seems like there is an android specific problem here (arm architecture compiler problem).  Looking around it seems as though there are some android TLS issues but looking through the boost source code it seems that they use pthread TLS mechanisms so this should not be an issue.

The boost port was built from https://github.com/MysticTreeGames/Boost-for-Android with boost 1.53.0.
