let calcualtions = 0;
function fibonacciRecursive(n){
  calcualtions ++;
	if (n<2) {
    return n;
  } 
  return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
// fibonacciRecursive(10);

// Now using the dynamic approach such that we store all the repeating values in cache so tha complexity is reduced to n 
let calcualtions2 = 0;
function fibonacciDynamic(){
  let cache = {};
  return function fibo(n){
		calcualtions2++;
    if (n in cache){
      return cache[n];
    } else {
      if(n<2){
				return n;
      } else {
				cache[n] = fibo(n-1) + fibo(n-2);
				return cache[n];
			}
    }
  };
}

let faster = fibonacciDynamic();
console.log('DP ' + faster(40));
console.log('No.of calculations/steps were ' + calcualtions2);
console.log('Slower ' + fibonacciRecursive(40));
console.log('No.of calculations/steps were ' + calcualtions);
