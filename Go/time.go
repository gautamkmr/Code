// Go offers built-in support for JSON encoding and
// decoding, including to and from built-in and custom
// data types.

package main

import "fmt"
import "time"
//import metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
/*
133         t2 := state.ObjectMeta.GetCreationTimestamp().Time
134         fmt.Println((time.Since(t2)).Round(time.Second))
*/


func main() {
   //t := time.Now();
   fmt.Println(time.Now().String())
   t1 := time.Now().Round(time.Second)
   time.Sleep(70 * time.Second)
   t2 := time.Now().Round(time.Second)
   fmt.Println(t2.Sub(t1))
   fmt.Println((time.Since(t1)).Round(time.Second))
}
