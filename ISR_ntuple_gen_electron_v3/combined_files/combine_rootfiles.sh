MG=`ls ../../*electron*madgraph*`
MCatNLO=`ls ../../*electron*MCatNLO*`

hadd -f MG.root $MG
hadd -f MCatNLO.root $MCatNLO
