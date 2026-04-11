class Parent {
    void func(int a) {
        System.out.println("Parent Method func " + a);
    }
}

class Child extends Parent {
    void func(int a) {
        System.out.println("Child Method func " + a);
    }
}

public class Main {
    public static void main(String[] args) {
        Parent p = new Parent();
        p.func(10); // Calls Parent's func method

        Child c = new Child();
        c.func(20); // Calls Child's func method

        Parent pc = new Child();
        pc.func(30); // Calls Child's func method due to method overriding
    }
}
