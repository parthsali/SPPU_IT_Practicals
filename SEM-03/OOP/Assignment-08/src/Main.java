public class Main {
    public static void main(String[] args) {

        Student s1  = new Student();
        FileHandling f = new FileHandling();
        s1.getData();
        f.writeData(s1);
        f.readData();

//        s1.displayData();
    }
}