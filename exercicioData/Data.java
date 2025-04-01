package exercicioData;
import java.util.Scanner;


public class Data {
    private int dia, mes, ano;

    public Data(Scanner sc){
        entradaDatas(sc);
    }
   
    public Data(){
        this.dia = 1;
        this.mes = 1;
        this.ano = 1;
    }
   
    public Data(int dia, int mes, int ano){
        if(!dataValida(dia, mes, ano)){
            this.dia = 1;
            this.mes = 1;
            this.ano = 1;
        }
        else{
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }
    }

    public Data(int dia, int mes, int ano, int dias){
        somaData(dia, mes, ano, dias);
    }

    public Data(Data data, int dias){
        somaData(data.dia, data.mes, data.ano, dias);
    }

    public void somaData(Data data, int dias){
        somaData(data.dia, data.mes, data.ano, dias);
    }

    private void somaData(int dia, int mes, int ano, int dias){
        int i;
        int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(dias < 0) dias *= -1;
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

    public static boolean dataValida(int dia, int mes, int ano){
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
        this.dia = sc.nextInt();
        this.mes = sc.nextInt();
        this.ano = sc.nextInt();
        if(!dataValida(this.dia, this.mes, this.ano)){
        System.out.printf("Data invalida. Tente novamente\n");
        entradaDatas(sc);
        }
}

    public static void imprimeDatas(Data[] vetorDatas){
        for(int i = 0; i < vetorDatas.length; i++)
            System.out.printf("Data: %02d/%02d/%04d\n", vetorDatas[i].dia, vetorDatas[i].mes, vetorDatas[i].ano);
    }

    public static void mostraData(Data data){
        System.out.printf("%02d/%02d/%02d\n", data.dia, data.mes, data.ano);
    }

    public byte getDia(){
        return (byte)dia;
    }

    public byte getMes(){
        return (byte)mes;
    }

    public byte getAno(){
        return (byte)ano;
    }

    public boolean setDia(int dia){
        if(dataValida(dia, mes, ano)){
            this.dia = dia;
            return true;
        }
        return false;
    }

    public boolean setMes(int mes){
        if(dataValida(dia, mes, ano)){
            this.mes = mes;
            return true;
        }
        return false;
    }

    public boolean setAno(int ano){
        if(dataValida(dia, mes, ano)){
            this.ano = ano;
            return true;
        }
        return false;
    }
  
    public boolean igualA(Data outraData){
        if(this.dia != outraData.dia || this.mes != outraData.mes || this.ano != outraData.ano) return false;
        return true;
    }
   
    public static boolean igualA(Data data, Data outraData){
        if(data.dia != outraData.dia || data.mes != outraData.mes || data.ano != outraData.ano) return false;
        return true;
    }
   
    public boolean diferenteDe(Data outraData){
        //if(this.dia != outraData.dia || this.mes != outraData.mes || this.ano != outraData.ano) return true;
        //return false;
        return !igualA(outraData);
    }
   
    public static boolean diferenteDe(Data data, Data outraData){
        //if(data.dia != outraData.dia || data.mes != outraData.mes || data.ano != outraData.ano) return true;
        //return false;
        return !igualA(data, outraData);
    }
    
    public boolean anteriorA(Data outraData){
        if(this.ano < outraData.ano) return true;
        if(this.ano > outraData.ano) return false;
        if(this.mes < outraData.mes) return true;
        if(this.mes > outraData.mes) return false;
        if(this.dia < outraData.dia) return true;
        return false;
    }

    public static boolean anteriorA(Data data, Data outraData){
        if(data.ano < outraData.ano) return true;
        if(data.ano > outraData.ano) return false;
        if(data.mes < outraData.mes) return true;
        if(data.mes > outraData.mes) return false;
        if(data.dia < outraData.dia) return true;
        return false;
    }

    public boolean posteriorA(Data outraData){
        if(this.ano < outraData.ano) return false;
        if(this.ano > outraData.ano) return true;
        if(this.mes < outraData.mes) return false;
        if(this.mes > outraData.mes) return true;
        if(this.dia <= outraData.dia) return false;
        return true;
    }
    
    public static boolean posteriorA(Data data, Data outraData){
        if(data.ano < outraData.ano) return false;
        if(data.ano > outraData.ano) return true;
        if(data.mes < outraData.mes) return false;
        if(data.mes > outraData.mes) return true;
        if(data.dia <= outraData.dia) return false;
        return true;
    }
    
    public boolean maiorOuIgual(Data outraData){
        if(this.ano < outraData.ano) return false;
        if(this.ano > outraData.ano) return true;
        if(this.mes < outraData.mes) return false;
        if(this.mes > outraData.mes) return true;
        if(this.dia < outraData.dia) return false;
        return true;
    }
    
    public static boolean maiorOuIgual(Data data, Data outraData){
        if(data.ano < outraData.ano) return false;
        if(data.ano > outraData.ano) return true;
        if(data.mes < outraData.mes) return false;
        if(data.mes > outraData.mes) return true;
        if(data.dia < outraData.dia) return false;
        return true;
    }
    
    public boolean menorOuIgual(Data outraData){
        if(this.ano < outraData.ano) return true;
        if(this.ano > outraData.ano) return false;
        if(this.mes < outraData.mes) return true;
        if(this.mes > outraData.mes) return false;
        if(this.dia <= outraData.dia) return true;
        return false;
    }
    
    public static boolean menorOuIgual(Data data, Data outraData){
        if(data.ano < outraData.ano) return true;
        if(data.ano > outraData.ano) return false;
        if(data.mes < outraData.mes) return true;
        if(data.mes > outraData.mes) return false;
        if(data.dia <= outraData.dia) return true;
        return false;
    }
}

