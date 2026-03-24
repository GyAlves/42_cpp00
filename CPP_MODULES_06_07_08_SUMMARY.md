# C++ Modules 06, 07 e 08 - Resumo

## Module 06 - C++ Casts (Conversões de Tipo)

### Tópicos Abordados
- Conversão explícita de tipos em C++
- Diferentes tipos de casts: static_cast, reinterpret_cast e dynamic_cast
- RTTI (Runtime Type Information)
- Serialização de dados
- Identificação de tipos em tempo de execução

### Exercícios

#### ex00: Conversão de Tipos Escalares
- **Objetivo**: Implementar conversão de tipos escalares (char, int, float, double)
- **Conceitos**: static_cast e conversão de strings para tipos primitivos
- **Classe**: ScalarConverter com método estático convert()
- **Funcionalidade**: Detectar tipo de entrada e converter para char, int, float e double

#### ex01: Serialização
- **Objetivo**: Serializar e deserializar ponteiros
- **Conceitos**: reinterpret_cast para conversão de ponteiros
- **Funcionalidade**:
  - Converter ponteiro de objeto para uintptr_t (serialização)
  - Converter uintptr_t de volta para ponteiro (deserialização)

#### ex02: Identificação de Tipo Real
- **Objetivo**: Identificar tipo real de objetos em hierarquia polimórfica
- **Conceitos**: dynamic_cast para identificação de tipos em tempo de execução
- **Funcionalidade**: Gerar objetos aleatórios de classes derivadas e identificar seus tipos reais

### Requisitos Técnicos
- Compilação com flag `-std=c++98`
- Classes não instanciáveis onde apropriado (métodos estáticos)
- Tratamento de casos especiais (inf, nan, conversões impossíveis)

---

## Module 07 - Templates (Programação Genérica)

### Tópicos Abordados
- Templates de função
- Templates de classe
- Programação genérica em C++
- Especialização de templates
- Instanciação de templates

### Exercícios

#### ex00: Introdução a Templates de Função
- **Objetivo**: Criar templates de função básicos
- **Conceitos**: Funções genéricas que funcionam com qualquer tipo
- **Funções típicas**:
  - swap: trocar valores de duas variáveis
  - min: retornar o menor de dois valores
  - max: retornar o maior de dois valores

#### ex01: Uso Avançado de Templates de Função
- **Objetivo**: Aplicar templates em contextos mais complexos
- **Conceitos**: Templates de função com arrays
- **Função típica**: iter - aplicar função a cada elemento de um array

#### ex02: Templates de Classe
- **Objetivo**: Criar classes genéricas usando templates
- **Conceitos**: Estruturas de dados genéricas
- **Classe típica**: Array - classe template que encapsula array com verificação de limites

### Requisitos Técnicos
- Compilação com flag `-std=c++98`
- Templates definidos em headers
- Código genérico que funciona com tipos built-in e classes customizadas
- Funções template devem estar em arquivos .hpp

---

## Module 08 - STL: Containers, Iterators & Algorithms

### Tópicos Abordados
- STL (Standard Template Library)
- Containers da STL (vector, list, deque, stack)
- Iteradores
- Algoritmos da STL
- Adaptadores de containers

### Exercícios

#### ex00: easyfind
- **Objetivo**: Criar função template para buscar elementos em containers
- **Conceitos**: Algoritmos e iteradores combinados com templates
- **Funcionalidade**: Função easyfind que busca primeira ocorrência de um valor em container
- **Containers suportados**: Qualquer container STL que suporte iteradores

#### ex01: Span
- **Objetivo**: Criar classe que armazena inteiros e calcula estatísticas
- **Conceitos**: Uso de algoritmos e iteradores com classes customizadas
- **Funcionalidade**:
  - Armazenar N inteiros
  - Adicionar números um a um ou por range
  - Calcular menor e maior span (diferença)
  - Lançar exceções quando apropriado

#### ex02: MutantStack
- **Objetivo**: Tornar std::stack iterável
- **Conceitos**: Adaptação de containers e herança de containers STL
- **Funcionalidade**:
  - Herdar de std::stack
  - Adicionar iteradores (begin, end)
  - Manter todas as funcionalidades de stack
  - Permitir iteração sobre elementos

### Requisitos Técnicos
- Compilação com flag `-std=c++98`
- Uso de containers STL (vector, list, stack, etc.)
- Implementação de iteradores
- Uso de algoritmos STL quando apropriado
- Tratamento de exceções

---

## Conceitos Gerais Aplicados em Todos os Módulos

### Boas Práticas C++98
- Orthodox Canonical Form (construtores, destrutor, operador de atribuição)
- Const correctness
- Exception handling
- RAII (Resource Acquisition Is Initialization)
- Encapsulamento

### Compilação e Testes
- Makefiles com regras: all, clean, fclean, re
- Flags de compilação: -Wall -Wextra -Werror -std=c++98
- Função main para demonstração em cada exercício
- Testes com diferentes tipos de dados

### Padrões de Design
- Static methods para funções utilitárias
- Templates para código genérico
- Exceções para tratamento de erros
- Iteradores para acesso a containers
