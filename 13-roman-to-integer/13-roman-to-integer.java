import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Stack;

public class Solution {
    
    /* Solution 2 */
    public int romanToInt(String s) {
        int sum=0;
        
        /* deduct.. since their existence will add up to sum twice */
        if(s.indexOf("IV")!=-1){sum-=2;}
        if(s.indexOf("IX")!=-1){sum-=2;}
        if(s.indexOf("XL")!=-1){sum-=20;}
        if(s.indexOf("XC")!=-1){sum-=20;}
        if(s.indexOf("CD")!=-1){sum-=200;}
        if(s.indexOf("CM")!=-1){sum-=200;}

        char c[]=s.toCharArray();
        int count=0;

       for(;count<=s.length()-1;count++){
           if(c[count]=='M') sum+=1000;
           if(c[count]=='D') sum+=500;
           if(c[count]=='C') sum+=100;
           if(c[count]=='L') sum+=50;
           if(c[count]=='X') sum+=10;
           if(c[count]=='V') sum+=5;
           if(c[count]=='I') sum+=1;

       }

       return sum;

    }
    
    /* Solution 1 */
    public int romanToInt1(String s) {
		LinkedHashMap<String, Integer> map = new LinkedHashMap<>();
		map.put("M",1000);
		map.put("CM",900);
		map.put("D",500);
		map.put("CD",400);
		map.put("C",100);
		map.put("XC",90);
		map.put("L",50);
		map.put("XL",40);
		map.put("X",10);
		map.put("IX",9);
		map.put("V",5);
		map.put("IV",4);
		map.put("I",1);
		
		if(s==null) return 0;
		if(s.trim().length()==0) return 0;
		
		s = s.trim();
		int len = s.trim().length()-1;
		Stack<Character> stack = new Stack<Character>();
		
		int reslt = 0;
		while(len>=0){
			char c = s.charAt(len);
			if(stack.isEmpty()) stack.push(c);
			else{
				int prev = map.get(stack.peek()+"");
				int curr = map.get(c+"");
				if(curr<prev) {
					reslt += map.get(c+""+stack.pop());
				}
				else{
					reslt += map.get(stack.pop()+"");
					stack.push(c);
				}
			}
			len--;
		}
		if(!stack.isEmpty()) reslt += map.get(stack.pop()+"");
		
		return reslt;
    }
}