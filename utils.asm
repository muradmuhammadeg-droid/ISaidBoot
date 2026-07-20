; Microsoft x64 Software Calling Convention Module
.code

; Export the function name so the C++ compiler can locate it
public SafeCpuHalt

SafeCpuHalt proc
    xor rax, rax    ; Clean out the primary accumulator register
    hlt             ; Halt the CPU execution thread safely
    ret             ; Return to caller
SafeCpuHalt endp

end
