public class ArrayQueue{

    private String[] items; // 存储数据的数组

    private int n;
    private int size;//记录数组容量

    private int head = 0;//队头
    private int tail = 0;//队尾

    public ArrayQueue(int capacity){
        items = new String[capacity];
        n = capacity;
    }
    
    /**
     * 入队
     */

    public boolean enQueue(String item){

        if(head == 0 && tail == n) return false;//数组满，无法入队列。
        else if(head != 0 && tail == n){//队头不在数组头且队尾在数组尾，需要进行数据搬移。
            for(int i = head; i < tail; i++){
                items[i - head] = items[i];
            }
            head = 0;
            tail = tail - head;
        }

        items[tail++] = item;//将数据入队列
        size ++;
        return true;
    }

    /**
     * 出队列
     * 队列空的时候，出队列失败。
     * 出队，head加一。
     */
    public String deQueue(){
        String res = null;
        if(head == tail) return res;
        res = items[head++];
        size--;
        return res;
    }
}
