// ljusblå 0, rosa 1, gul 2, svart 3, grön 4, ljusbrun 5, ljusgrå 6, brun, 7
// mörkblå 8, röd 9, orange 10, vit 11, gulgrön 12, lila 13, mörkgrå 14, turkos 15
COORDS = [[[|
    =
    A1=0
    A3=13
    A5=5
    A7=4
    A9=1
    A11=13 
    A13=4
    A15=3
    B1=2
    B3=3
    B5=11
    B7=2
    B9=15
    B11=8
    B13=9
    B15=13
    C1=4
    C3=6
    C5=14
    C7=6
    C9=4
    C11=0
    C13=11
    C15=12
    D1=3
    D3=10
    D5=14
    D7=5
    D9=11
    D11=9
    D13=10
    D15=9
    
    Q1=9
    Q3=8
    Q5=15
    Q7=9
    Q9=11
    Q11=8
    Q13=5
    Q15=3
    R1=7
    R3=15
    R5=7
    R7=14
    R9=10
    R11=11
    R13=4
    R15=14
    S1=13
    S3=5
    S5=3
    S7=10
    S9=14
    S11=13
    S13=0
    S15=12
    T1=12
    T3=10
    T5=1
    T7=7
    T9=14
    T11=7
    T13=10
    T15=2
]]]

FINGERPRINTS = [[[,
    amdRKfgpJk7yEW1KE9p18JT0UOyVD#Gy7H2NmrHVN5gAfcP2yum8VU=EGA
    YpCn#WfE9LD0ql60A0wgRI39SPFO743vxxGEXHOt9@G4Qr@23pHdxS=VGA Danish
    @JiqqfVqQcv0VZtPs9EaUmr1HkctP5swqseMZ62l5@yS3ZP4kVgsBS=EGA Danish
    24IeOWfE9LD0ql60A0mSc@X9SPFO743vxxGEXHOt9@G4Qr@23pHdxS=Swedish
]]]

charset[hugo]:
    height = 8
    char[0x31]: bits = 02`7c`02`02
    char[0x33]: bits = 02`42`52`40`08
    char[0x35]: bits = 30`52`52`52`50`08
    char[0x37]: bits = 20`40`40`46`40`60
    char[0x39]: bits = 10`08`4a`4a`40`28
    char[0x41]: bits = 06`18`28`68`10`06
    char[0x42]: bits = 3e`52`52`52`20`08
    char[0x43]: bits = 1c`02`42`42`60
    char[0x44]: bits = 3e`42`40`40`20`18
    char[0x45]: bits = 3e`52`52`52`52`42
    char[0x46]: bits = 3e`50`50`50`50`40
    char[0x47]: bits = 1c`02`42`52`52`1c
    char[0x48]: bits = 3e`10`10`10`10`2e
    char[0x49]: bits = 42`7c`42`42
    char[0x4b]: bits = 3e`10`10`08`04`02
    char[0x4c]: bits = 3e`02`02`02`02`02
    char[0x4e]: bits = 3e`20`10`08`04`3a
    char[0x4f]: bits = 1c`02`42`42`40`38
    char[0x50]: bits = 3e`48`48`48`40`20
    char[0x51]: bits = 1c`02`42`41`40`38
    char[0x52]: bits = 3e`48`48`48`44`22
    char[0x53]: bits = 12`52`52`50`08
    char[0x54]: bits = 40`7e`40`40
    char[0x55]: bits = 3c`02`02`02
    char[0x55]: bits = 3c`02`02`02`00`78
    char[0x56]: bits = 20`18`06`02`18`20
    char[0x63]: bits = ff`81`ef`28`28`ef`81`ff`e0`98`66`19`19`66`98`e0`e7`a5`bd`81`bd`a5`e7
end

script[cpscript]:
    code = [[[$(CRLF)
        func update()
        {
          if (!script_running(cpscript))
          {
            echo("Region: " + scraper_fingerprint("BbzR7#N#F"));

            match = scraper_match("BbzR7#N#F", "$$(FINGERPRINTS)");

            if (match)
            {
              coord = scraper_string("BrNMKwAOu", "hugo", 0x6);
              echo("Coordinates: " + coord);
              
              if (coord != "")
              {
                

                echo("Coord digits: " + substr(coord, 1));
                digits = 16 - int(substr(coord, 1));
                echo("New coord " + substr(coord, 0, 1) + digits);
			    if(game_id() == "ite-hugo2:pc-dk-dos")
			    { 
				  coord = substr(coord, 0, 1) + str(digits);
			    }
                answer = strmap(coord, "$$(COORDS)");
                echo("Answer: " + answer);				
	        if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", answer);
              }
            }
          }
        }

        func cpauto(answer)
        {
          input_lockout(true);
          for (i = 0; i < answer; i++)
            keyboard_type("`50");
           
          keyboard_type("\r");
          sleep(1000);
          input_lockout(false);
        }
    ]]]
end