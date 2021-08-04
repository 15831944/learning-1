package certification.genericscollections.collections;

import java.util.ArrayDeque;
import java.util.EmptyStackException;
import java.util.Queue;
import java.util.Stack;

public class Queues {
    public static void main(String...args) {
        Queue<Integer> queue = new ArrayDeque<>();
        System.out.println(queue.offer(10)); //true
        System.out.println(queue.offer(20)); //true
        System.out.println(queue.peek()); //10 did not remove
        System.out.println(queue.poll()); //10
        System.out.println(queue.peek());//20
        System.out.println(queue.poll());//20
        System.out.println(queue.peek());//null

        ArrayDeque<Integer> stack = new ArrayDeque<>();
        stack.push(10);
        stack.push(20);
        System.out.println(stack.peek());//20
        System.out.println(stack.pop());//20
        System.out.println(stack.peek());//10
        System.out.println(stack.pop());//10
        System.out.println(stack.peek());//null

        System.out.println("Real old Stack, this should be not used anymore in new code");
        Stack<Integer> stack1 = new Stack<Integer>();
        stack1.push(10);
        stack1.push(20);
        System.out.println(stack1.peek());//20
        System.out.println(stack1.pop());//20
        System.out.println(stack1.peek());//10
        System.out.println(stack1.pop());//10
        try {
            System.out.println(stack1.peek());//throw exception
        } catch (EmptyStackException e) {
            System.out.println("Expected exception vs ArrayDequeue which return null");
        }
    }
}
