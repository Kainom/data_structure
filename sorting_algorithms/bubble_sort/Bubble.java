import java.util.Random;

public class Bubble{

    private static final int TAM = 199999;
    private  static int[] array = new int[TAM];
    private static Random rand = new Random();




private static void randomArray(){
    for(int i =0;i<TAM;i++){
        array[i] = rand.nextInt(TAM);
    }
}


private static void bubbleSort2() {
    int i, j, troca = 0, aux;
  
    for (i = 0; i < TAM; i++) {
      for (j = 0; j < TAM - i - 1; j++) {
        if (array[j] > array[j + 1]) {
          aux = array[j];
          array[j] = array[j + 1];
          array[j + 1] = aux;
          troca = 1;
        }
      }
      if (troca == 0)
        break;
    }
  }



private  static void printAray(){
    for(int value:array){
        System.out.print(value + " ");
    }
}

private static void arrayDisorderly(){
    for(int value:array){

    }
}





    public static void main(String[] args) {
        randomArray();

        double start = System.currentTimeMillis();
        
        arrayDisorderly();
        
        double end = System.currentTimeMillis();

        System.out.println("Time: " + (end - start) + "ms");


         start = System.currentTimeMillis();

        bubbleSort2();

        end = System.currentTimeMillis();

        System.out.println("Time: " + (end - start) + "ms");



    }


}