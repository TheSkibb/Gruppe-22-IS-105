//Author: Kristian Skibrek
//Date: 12/03/2021
//version: 1.0

import java.net.*;
import java.io.*;
import java.util.Random;

public class QuotesServer{
    
    public static void main(String[] args){
        Random randomgenerator = new Random();
        /*quotes from https://www.briantracy.com/blog/personal-success/26-motivational-quotes-for-success/ */
        String quotes[] = {
        
        "The Best Way To Get Started Is To Quit Talking And Begin Doing",
        "The Pessimist Sees Difficulty In Every Opportunity. The Optimist Sees Opportunity In Every Difficulty",
        "Don’t Let Yesterday Take Up Too Much Of Today",
        "You Learn More From Failure Than From Success.",
        "It’s Not Whether You Get Knocked Down, It’s Whether You Get Up.",
        "If You Are Working On Something That You Really Care About, You Don’t Have To Be Pushed. The Vision Pulls You",
        "People Who Are Crazy Enough To Think They Can Change The World, Are The Ones Who Do."
        };
        try{
            ServerSocket sock = new ServerSocket(6013);

            /*now listen for connections*/
            while(true){
            Socket client = sock.accept();

            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

            /*write the date to the socket*/
    
            pout.println(quotes[randomgenerator.nextInt(quotes.length)]);
            
            /*close the socket nd resume*/
            /*listenin for connections*/
            client.close();
            }
        }
        catch (IOException ioe){
            System.err.println(ioe);
        }
    }

}

