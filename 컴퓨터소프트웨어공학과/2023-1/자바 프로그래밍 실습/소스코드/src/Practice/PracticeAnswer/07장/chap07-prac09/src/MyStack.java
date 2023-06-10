import java.util.ArrayList;
import java.util.Vector;

// MyStack은 push() 새로 추가되는 아이템을 항상 맨 앞에 삽입한다.
// 그러므로 pop() 역시 맨 앞에 있는 아이템을 삭제한다. 
public class MyStack<T> implements IStack<T> {
	Vector<T> l = null;
	public MyStack() {
		l = new Vector<T>();
	} 	// 생성자

	@Override
	public T pop() {
		if (l.size() == 0)
			return null; 
		else {
			return l.remove(0); // 맨 앞에 있는 아이템 삭제
		}
	}

	@Override
	public boolean push(T ob) {
		l.add(0, ob); // 맨 끝에 삽입 
		return true;
	}
}
