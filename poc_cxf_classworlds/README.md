# poc of CXF using REST on classworlds and dynamic routes

Replace /home/gaby/public-git/learning/poc_cxf_classworlds everywhere it is in the 
code or file with the location where the project has been checkout.

run from application/target

after build the project make package of route1

run with

java -classpath ./lib/plexus-classworlds-2.6.0.jar -Dclassworlds.conf=./config/classworlds.conf org.codehaus.plexus.classworlds.launcher.Launcher

see the open api to make request to the REST API.

when the following message "Replace the route" appears build the route2 and press r

see the open api with the new routes and make request to the REST API.