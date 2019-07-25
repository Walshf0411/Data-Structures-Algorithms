import java.io.* ;
import java.util.*;

public class Maximum {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the list of elements whose max has to be calculated");
        String s[] = sc.nextLine().split(" ");
        int arr[] = new int[s.length];
        for (int i = 0;i<s.length;i++){
            arr[i] = Integer.parseInt(s[i]);
            // System.out.println(arr[i]);
        }
        System.out.println("enter the value of n where n is the nth maximum element of the array ");
        int n = sc.nextInt();
        int max = (new Maximum()).getNthMaximum(arr , n);
        System.out.println(max);
        sc.close();
    }
    int getNthMaximum(int arr[], int n){
        HashMap<Integer,Integer> hash = new HashMap<Integer,Integer>();
        // This will insert values of arr along with their occurrences
        for(int i =0 ;i< arr.length;i++){
            if(hash.containsKey(arr[i])){
                hash.put(arr[i], hash.get(arr[i]) + 1);
            } else {
                hash.put(arr[i], 1);
            }
        }
        // Now checking if the value of n is greater than the hash.size() if yes the simply return -1
        if(n > hash.size()){
            return -1;
        }
        else {
            // To convert hashmap to sorted hashmap convert it into a tree map 
            Map<Integer,Integer> sortedhash = new TreeMap<Integer,Integer>(hash);// This was done to sort the hash map.
            int max = returnMax(sortedhash.keySet(), n);
            return max;
        }
        // System.out.println(hash.size());
        // return 0;
    }
    // Since the keyset() method only returns a Set<(type T)> therefore converted it to the list to get elements from it as well 
    int returnMax(Set<Integer> s, int n){
        List<Integer> list = new ArrayList<Integer>();
        for(Integer l : s){
            list.add(l);
        }
        // return list.get(n);
        System.out.println(list);
        return list.get(list.size()-n);
    } 
}