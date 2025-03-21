package exercicioData;
import java.util.Scanner;


public class TesteData {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.printf("Digite quantos elementos tem o vetor: ");
        int n = sc.nextInt();
        Data[] vetor = Data.alocaListaDatas(n);
        Data.entradaDatas(vetor);
        Data.imprimeDatas(vetor);
        sc.close();
    }
}
