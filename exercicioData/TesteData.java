package exercicioData;
import java.util.Scanner;


public class TesteData {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        /*System.out.printf("Digite quantos elementos tem o vetor: ");
        int n = sc.nextInt();*/
        Data[] vetor = new Data[2];
        /*for(int i = 0; i < n; i++)
            vetor[i] = new Data(sc);
        vetor[n] = new Data(12,5,2003,30);*/
        vetor[0] = new Data(12,12,2005);
        vetor[1] = new Data(vetor[0], 30);
        Data.imprimeDatas(vetor);
        sc.close();
    }
}
