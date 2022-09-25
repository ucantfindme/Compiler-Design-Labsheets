import java.io.*;
import java_cup.*;
import java_cup.runtime.*;
public class Main{ 
    public static void main(String[] args)throws Exception{
        parser p = new parser(new Yylex(new FileReader("input"))); 
        p.parse(); 
    } 
}