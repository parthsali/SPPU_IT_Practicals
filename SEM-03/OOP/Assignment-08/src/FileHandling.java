import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileHandling {
    public void readData(){
        try{
            File file = new File("demo.txt");
            Scanner sc = new Scanner(file);
            while (sc.hasNextLine()){
                String line = sc.nextLine();
                System.out.println(line);
            }
            sc.close();
        }catch (FileNotFoundException e){
            System.out.println(e.getMessage());
        }
    }

    public void writeData(Student obj){
        try{
            FileWriter fw = new FileWriter("demo.txt");
            String line = String.valueOf(obj.toString().split(" "));
            fw.write(line);
            fw.close();
        }catch (IOException e){
            System.out.println(e.getMessage());
        }
    }
}
