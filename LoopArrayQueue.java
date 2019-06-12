/**
 * 循环队列
 * 数组实现
 * 队列空：head == tail
 * 队列满：(tail + 1) % n == head
 * tail所指向的位置实际没有存储数据
 */

public class LoopArrayQueue{
    private String items[];//存储数据的数组

    private int n;
    private int size = 0;//记录数组容量

    private int head = 0;
    private int tail = 0;

    public LoopArrayQueue(int capacity){
        items = new String[capacity];
        n = capacity;
    }

    public boolean enQueue(String item){
        if((tail + 1) % n == head) return false;
        items[tail] = item;
        tail = (tail + 1) % n;
        size++;
        return true;
    }

    public String deQueue(){
        String res = null;
        if(head == tail) return res;
        res = items[head];
        head = (head + 1) % n;
        size--;
        return res;
    }

}