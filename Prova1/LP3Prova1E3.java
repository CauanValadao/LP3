package Prova1;

public class LP3Prova1E3 {
    public static void main(String[] args){
        Lampada vet[] = new Lampada[10];

        for(int i = 0; i < vet.length; i++)
            vet[i] = new Lampada();
        
        System.out.printf("Lampadas criadas: \n\n");	

        for(int i = 0; i < vet.length; i++)
            System.out.printf("%f\n", vet[i].getIntensidade());

        for(int i = 0; i < vet.length; i++)
            vet[i].setIntensidade((i + 1.0f)/10.0f);
        
        System.out.printf("\nAumentando a intensidade das lampadas: \n\n");

        for(int i = 0; i < vet.length; i++)
            System.out.printf("%f\n", vet[i].getIntensidade());
    }
}
