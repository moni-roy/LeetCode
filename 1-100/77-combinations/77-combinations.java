public class Solution {
    // HashMap<String, List<List<Integer>>> map = new HashMap<>();
    public List<List<Integer>> combine(int n, int k) {
		List<List<Integer>> list = new LinkedList<List<Integer>>();
		if(k<1) return list;
		return combine(n, k, 1);
	}
	
	private List<List<Integer>> combine(int n, int k, int start) {
		List<List<Integer>> list = new LinkedList<List<Integer>>();
		if(k<1) return list;		
		// if(map.containsKey(k+":"+n+":"+start)) return map.get(k+":"+n+":"+start);
		
		for(int i=start;i<=n;i++){
			if(k==1){
				List<Integer> l = new LinkedList<Integer>();
				l.add(i);
				list.add(l);
			}
			else{
				List<List<Integer>> sub = combine(n, k-1, i+1);
				if(sub!=null){
					for(List<Integer> l: sub){
						List<Integer> ll = new LinkedList<Integer>();
						ll.addAll(l);
						ll.add(0, i);
						list.add(ll);
					}
				}
			}
		}
		// map.put(k+":"+n+":"+start, list);
		return list;
	}
}