import java.io.*;
import java.net.*;

class TCPServer{
public static void main(String argv[]) throws Exception{
String clientMessage;
//setter socket til 6789
ServerSocket messageSocket = new ServerSocket(6789);
//evig loop som tar imot messages fra socket og printer til konsollen (obs ingen løsning i programmet for å avslutte det, må derfor manuelt termineres)
while(true) {
    Socket connectionSocket = messageSocket.accept();
    BufferedReader bd = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
    clientMessage = bd.readLine();
    System.out.println("Client message recieved: " + clientMessage + "\n");
}
}
}
