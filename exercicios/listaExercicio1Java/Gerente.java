package listaExercicio1Java;

public class Gerente extends Funcionario{
    private String departamento;

    public Gerente(String departamento, int cargaHoraria, double salario, String nome, int idade) {
        super(cargaHoraria, salario, nome, idade);
        this.departamento = departamento;
    }
    public Gerente(String departamento, int cargaHoraria, double salario, String nome) {
        this(departamento, cargaHoraria, salario, nome, 18);
    }
    public Gerente(String departamento, int cargaHoraria, double salario) {
        this(departamento, cargaHoraria, salario, "fulano", 18);
    }
    public Gerente(String departamento, int cargaHoraria) {
        this(departamento, cargaHoraria, 1000, "fulano", 18);
    }
    public Gerente(String departamento, double salario) {
        this(departamento, 40, salario, "fulano", 18);
    }
    public Gerente(String departamento, String nome, int idade) {
        this(departamento, 40, 1000, nome, idade);
    }
    public Gerente(String departamento, String nome) {
        this(departamento, 40, 1000, nome, 18);
    }
    public Gerente(String departamento) {
        this(departamento, 40, 1000, "fulano", 18);
    }
    public Gerente() {
        this("TI", 40, 1000, "fulano", 18);
    }
    public String getDepartamento() {
        return departamento;
    }
    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }
}
