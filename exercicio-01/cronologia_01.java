import java.util.Scanner;

public class cronologia_01 {
    public static void main(String[] args){
        int dia = 32, mes = 42, ano = 74;

        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o dia");
        dia = sc.nextInt();

        System.out.println("Digite o mes");
        mes = sc.nextInt();

        System.out.println("Digite o ano");
        ano = sc.nextInt();

        System.out.println("\nVoce digitou a data: " + dia + "/" + mes + "/" + ano);
        
        sc.close();
    }
}
