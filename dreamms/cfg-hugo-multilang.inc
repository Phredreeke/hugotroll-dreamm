REGISTRY = [[[$(CRLF)
    REGEDIT4
    [HKEY_LOCAL_MACHINE\Software]
    
    [HKEY_LOCAL_MACHINE\Software\ITESystemPC\Core]
    "CFGPath"="C:\$$(LANGCONFIG)"
]]]

script[init]:
    code = [[[$(CRLF)
    if (LANGSELECT = true) {
        winregistry_import_raw("$$(REGISTRY)");
    }
    ]]]
end