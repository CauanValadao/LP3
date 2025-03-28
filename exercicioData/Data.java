package exercicioData;
import java.util.Scanner;


public class Data {
    public int dia, mes, ano;

    public Data(Scanner sc){
        entradaDatas(sc);
    }
    public Data(){
        dia = 1;
        mes = 1;
        ano = 1;
    }
    public Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
    public Data(int dia, int mes, int ano, int dias){
        somaData(dia, mes, ano, dias);
    }

    public Data(Data data, int dias){
        somaData(data.dia, data.mes, data.ano, dias);
    }

    private void somaData(int dia, int mes, int ano, int dias){
        int i;
        int meses[] = {31, (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        dias += dia;

        while(dias != 0){
            meses[1] = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
            for(i = mes-1; i < 12; i++){
                if(dias > meses[i]) dias -= meses[i];
                else{
                    this.dia = dias;
                    this.mes = i + 1;
                    this.ano = ano;
                    dias = 0;
                    break;
                }
            }
            ano += 1;
            mes = 1;
        }

    }

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
    public void entradaDatas(Scanner sc){
        System.out.printf("Digite uma data (dd/mm/aaaa):\n");
        dia = sc.nextInt();
        mes = sc.nextInt();
        ano = sc.nextInt();
        if(!dataValida()){
        System.out.printf("Data invalida. Tente novamente\n");
        entradaDatas(sc);
        }
}

    public static void imprimeDatas(Data[] vetorDatas){
        for(int i = 0; i < vetorDatas.length; i++)
            System.out.printf("Data: %02d/%02d/%04d\n", vetorDatas[i].dia, vetorDatas[i].mes, vetorDatas[i].ano);
    }
}

