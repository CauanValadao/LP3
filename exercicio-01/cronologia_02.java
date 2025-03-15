import java.util.Scanner;

public class cronologia_02 {
    
    public static void main(String[] args){
        int dia, mes, ano;

        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o dia");
        dia = sc.nextInt();

        System.out.println("Digite o mes");
        mes = sc.nextInt();

        System.out.println("Digite o ano");
        ano = sc.nextInt();

        boolean dataok = true;

        if(mes < 1 || mes > 12){
            System.out.println("Mes invalido");
            dataok = false;
        }
        else if(dia < 1 || dia > 31){
            System.out.println("Dia invalido");
            dataok = false;
        }
        else if(((mes == 4 || mes == 6 || mes == 9 || mes ==1) && dia > 31)){
            System.out.println("Dia invalido");
            dataok = false;
        }
        else if(mes == 2){
            boolean bissexto = false;
            if(((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)))
                bissexto = true;

            if(dia > 29 || (dia == 29 && !bissexto)){
                 System.out.println("Dia invalido\n");
                 dataok = false;
            }
        }

        if(dataok)
        System.out.println("\nVoce digitou a data: " + dia + "/" + mes + "/" + ano);

        sc.close();
    }
}
