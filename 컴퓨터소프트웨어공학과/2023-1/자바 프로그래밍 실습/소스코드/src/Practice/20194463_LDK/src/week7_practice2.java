
public class week7_practice2 {
	
	public week7_practice2()
	{
		
	}
	

	static boolean isOperator(char ch)
	  {
	      if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
	      return true;
	      
	      return false;
	  }
	  
	public void pop()
	{
		
	}
	  public void eval(String exp)
	  {
		  
	      int n = exp.length();
	      
	      for(int i=0;i<n;i++)
	      {
	        if(isOperator(exp.charAt(i)))
	        {
	        // pop top 2 operands.
	        int op1 = week7_practice2.pop();
	        int op2 = week7_practice2.pop();
	              
	        // evaluate in reverse order i.e. op2 operator op1.
	        switch(exp.charAt(i))
	        {
	            case '+': week7_practice2.push(op2 + op1);
	                      break;
	                      
	            case '-': week7_practice2.push(op2 - op1);
	                      break;
	                      
	            case '*': week7_practice2.push(op2 * op1);
	                      break;
	                
	            case '/': week7_practice2.push(op2 / op1);
	                      break;
	                    
	        }
	        
	        }
	        // Current Char is Operand simple push into stack
	        else
	        {
	        // convert to integer
	        int operand = exp.charAt(i) - '0';
	        week7_practice2.push(operand);
	        }
	      }
	      
	      // Stack at End will contain result.
	      System.out.println(week7_practice2.pop());
	  }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		week7_practice2 s = new week7_practice2();
		int a = s.eval("23+5*9+");
		System.out.println(a);

	}

}
