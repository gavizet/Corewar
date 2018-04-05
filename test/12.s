.name "Test sti : instruction 11"
.comment "Does sti work ?"

sti r2, r8, r4
sti r2, 12, r4
sti r2, r8, %12
sti r2, 7, %42
sti r2, r8, %5743854378954378953
sti r2, 12, r4
sti r2, %42, r7
sti r2, %234, %12
sti r2, %343, r2
