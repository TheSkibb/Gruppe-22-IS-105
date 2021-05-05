//Author: Kristian Skibrek
//Date: 12/03/2020
//version: 1.0

import java.net.*;
import java.io.*;

public class DateClient{
	public static void main(String[] args){
		try{
			/*make connection to server socket*/
			Socket sock = new Socket("127.0.0.1",6013);

			InputStream in = sock.getInputStream();
			BufferedReader bin = new BufferedReader(new InputStreamReader(in));

			/*read the date frem the socket*/
			String line;
			
			while((line = bin.readLine()) != null){
				System.out.println(line);
			}

			/*close the socket connection*/
			sock.close();

		}
		
		catch(IOException ioe){
			System.err.println(ioe);
		}
	}

}
