package listaExercicio1Java;

public class Carro {
    private String marca;
    private String modelo;
    private int ano;

    public Carro(String marca, String modelo, int ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }

    public Carro(String marca, String modelo){
        this(marca, modelo, 2000);
    }

    public Carro(String marca, int ano){
        this(marca, "modelo", ano);
    }

    public Carro(String marca){
        this(marca, "modelo", 2000);
    } 
    public Carro(int ano){
        this("marca", "modelo", ano);
    }

    public Carro(){
        this("marca", "modelo", 2000);
    }

    public void exibir_info(){
        System.out.println("marca: " + marca + " / modelo: " + modelo + " / ano: " + ano);
    }
    

}
