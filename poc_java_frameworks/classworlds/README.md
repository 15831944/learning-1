# classworlds examples

This will build and application using classworlds and dynamic loading of jars.

Replace in code and files the follwing /home/gaby/public-git/learning/poc_java_frameworks/classworlds 
with your checkout location.

Build the application.

Build the client, this will deploy the client

run from server/target with:

java -classpath ./lib/plexus-classworlds-2.6.0.jar -Dclassworlds.conf=./config/classworlds.conf org.codehaus.plexus.classworlds.launcher.Launcher

when the message "Replace the client" appears build the client2 and press c

This could be run also using standalone:

java -classpath /home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/lib/plexus-classworlds-1.2-alpha-13.jar -jar server-1.0-SNAPSHOT.jar 

