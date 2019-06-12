public class LinkedQueue{
    //定义一个节点类
    private class Node{
        String value;
        Node next;
    }

    private int size = 0;
    private Node head;
    private Node tail;

    public LinkedQueue(){};

    public boolean enQueue(String item){
        Node newNode = new Node();
        newNode.value = item;
        
        if(size == 0) head = newNode;
        else tail.next = newNode;

        tail = newNode;
        size++;
        return true;
    }

    public String deQueue(){
        String res = null;
        if(size == 0) return res;
        if(size == 1) tail = null;
        res = head.value;
        head = head.next;
        size--;
        return res;
    }
}