package exercicioData;
import java.util.Scanner;


public class Data {
    private int dia, mes, ano;

    private boolean dataValida(){
        if(mes < 1 || mes > 12) return false;
        if(dia < 1 || dia > 31) return false;
        if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
        if(mes == 2){
            boolean bissexto = false;
            if(((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)))
                bissexto = true;

            if(dia > 29 || (dia == 29 && !bissexto)) return false;
        }
        return true;
    }
    public static void entradaDatas(Data[] vetorDatas){
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < vetorDatas.length; i++){
            System.out.printf("Digite uma data (dd/mm/aaaa):\n");
            vetorDatas[i].dia = sc.nextInt();
            vetorDatas[i].mes = sc.nextInt();
            vetorDatas[i].ano = sc.nextInt();
            if(!vetorDatas[i].dataValida()){
                System.out.printf("Data invalida. Tente novamente\n");
                i--;
            }
        }
        sc.close();
    }

    public static void imprimeDatas(Data[] vetorDatas){
        for(int i = 0; i < vetorDatas.length; i++)
            System.out.printf("Data: %02d/%02d/%04d\n", vetorDatas[i].dia, vetorDatas[i].mes, vetorDatas[i].ano);
    }

    public static Data[] alocaListaDatas(int n){
        Data[] vetor = new Data[n];
        for(int i = 0; i < n; i++)
            vetor[i] = new Data();
        return vetor;
    }
}

