# MatrixAndPlotterExample
Matrix and Plotter Example

## RLC Circuit State Space Model Development

### Circuit Diagram
```
                 R1      L1
         .------VVVV----UUUU-------.----------.
         |                         |          |    +
      + ,'.        ------>          >         |     
  Vg   (   )         iL         R2  >     C1 ===   vC
      - `.'                         >         |    
         |                         |          |    -
         +-------------------------'----------'
        _|_
         -
         
Desired outputs: inductor current iL and capacitor voltage vC
```
## Block Diagram
```
        .---------------.
        |    A  |  B    |----> iL
Vg ---->|   ----+----   |
        |    C  |  D    |----> vC
        '---------------'
```

### KVL for inductor current and KCL for capacitor voltage
```
Vg = iL * R1 + iL' * L1 + vC 
iL = vC / R2 + vC' * C1
```
### Standard ODE form
```
iL' = -R1/L1 * iL - 1/L1 * vC + 1/L1 * Vg
vC' = 1/C1 * iL - 1/(R2*C1) * vC  
```
### Define State Space Vectors
```
x = [ iL  vC ]T
u = [ Vg ]T
y = [ iL  vC ]T
```
### Define State Equation (x' = A * x + B * u)
```
[ iL' ]   =  [ -R1/L1   -1/L1      ]  *  [ iL ]  +  [  1/L  ] * [ Vg ]
[ vC' ]      [   1/C1   -1/(R2*C1) ]     [ vC ]  +  [  0    ]
```
### Define Output Equation (y = C * x + D * u)
```
[ iL ]   =  [ 1  0 ]  *  [ iL ]  +  [ 0 ] * [ Vg ]
[ vC ]      [ 0  1 ]     [ vC ]     [ 0 ]
```
### State Space Matrices
```
A = [ -R1/L1   -1/L1      ]
    [   1/C1   -1/(R2*C1) ]
    
B = [  1/L  ]
    [  0    ]
    
C = [ 1  0 ]
    [ 0  1 ]
    
D = [ 0 ]
    [ 0 ]
```
