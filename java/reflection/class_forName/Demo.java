public class Demo {
  public Demo() {
    System.out.println("Hi!");
  }

  public static void main(String[] args) {
    try {
      Class clazz = Class.forName("Demo");
      Demo demo = (Demo)clazz.newInstance();
    } catch(Exception e) {
    }
  }
}

