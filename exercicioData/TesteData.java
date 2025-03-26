package exercicioData;
import java.util.Scanner;


public class TesteData {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.printf("Digite quantos elementos tem o vetor: ");
        int n = sc.nextInt();
        Data[] vetor = new Data[n];
        for(int i = 0; i < n; i++)
            vetor[i] = new Data(sc);
        
        Data.imprimeDatas(vetor);
        sc.close();
    }
}
