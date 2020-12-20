compilation tout le code java :  dans Projet1
    javac -d ./cls/ -cp ./misc/json.jar -sourcepath ./src/java/ ./src/java/*.java
execution serveur : dans /cls : 
    java -cp ../../misc/"json.jar:." ServeurHttp
