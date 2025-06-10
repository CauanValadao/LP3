package listaExercicio1Java;

public class Funcionario extends Pessoa {
    private int cargaHoraria;
    private double salario;

    public Funcionario(int cargaHoraria, double salario, String nome, int idade){
        super(nome, idade);
        this.cargaHoraria = cargaHoraria;
        this.salario = salario;
    }
    public Funcionario(int cargaHoraria, double salario, String nome){
        this(cargaHoraria, salario, nome, 18);
    }
    public Funcionario(int cargaHoraria, double salario){
        this(cargaHoraria, salario, "fulano", 18);
    }
    public Funcionario(int cargaHoraria){
        this(cargaHoraria, 1000, "fulano", 18);
    }
    public Funcionario(double salario){
        this(40, salario, "fulano", 18);
    }
    public Funcionario(String nome, int idade){
        this(40, 1000, nome, idade);
    }
    public Funcionario(String nome){
        this(40, 1000, nome, 18);
    }
    public Funcionario(){
        this(40, 1000, "fulano", 18);
    }

    public int getCargaHoraria() {
        return cargaHoraria;
    }
    public void setCargaHoraria(int cargaHoraria) {
        if(cargaHoraria > 0) this.cargaHoraria = cargaHoraria;
    }
    public double getSalario() {
        return salario;
    }
    public void setSalario(double salario) {
        if(salario > 0) this.salario = salario;
    }

}
