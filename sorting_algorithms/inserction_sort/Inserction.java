import java.util.Random;

public class Inserction {

    private static final int TAM = 199999;
    private static int[] array = new int[TAM];
    private static Random rand = new Random();

    private static void randomArray() {
        for (int i = 0; i < TAM; i++) {
            array[i] = rand.nextInt(TAM);
        }
    }

    private static void inserction() {
        int i = 1, j, troca = 0, aux, pivo;

        while (i < TAM) {
            pivo = array[i];

            for (j = (i - 1); i >= 0 && troca != 1; i--) {
                 if (array[j] > pivo) {
                    aux = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = aux;
                }
                {
                    troca = 1;
                    break;
                }

            }
            i++;
        }
    }

    private static void printAray() {
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    private static void arrayDisorderly() {
        for (int value : array) {

        }
    }

    public static void main(String[] args) {
        randomArray();

        double start = System.currentTimeMillis();

        arrayDisorderly();

        double end = System.currentTimeMillis();

        System.out.println("Time: " + (end - start) + "ms");

        start = System.currentTimeMillis();

        inserction();

        end = System.currentTimeMillis();

        System.out.println("Time: " + (end - start) + "ms");

    }

}