/**
 * 此程序借助一个辅助栈来判断给定的弹出序列是否为该栈的弹出序列
 */
public boolean IsPopOrder(int[] pushA, int[] popA){
    if(pushA == null || popA == null || pushA.length == 0 || popA.length == 0){
        return false;
    }
    LinkedList<Integer> stack = new LinkedList();
    int popIndex = 0;
    for(int i = 0; i < pushA.length; ++i){
        stack.push(pushA[i]);
        while(!stack.isEmpty() && stack.peek() == popA[popIndex]){
            stack.pop();
            popIndex++;
        }
    }
    return stack.isEmpty();
}