package listaExercicio1Java;

public class CarroMain {
    
    public static void main(String[] args){
        Carro[] carros = new Carro[2];
        carros[0] = new Carro(100);
        carros[1] = new Carro("100");

        for(int i = 0; i < 2; i++){
            carros[i].exibir_info();
        }
    }
}
