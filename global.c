// File Data in 2D array [row][column]
float data[100][10];

// Number of NORMAL and altered data
float noOfNormalData = 0, noOfAlteredData = 0;

// Values of normal and altered prior probability
float normalPriorProb, alteredPriorProb;

// Probabilities for season of analysis
float winterNormal, springNormal, summerNormal, fallNormal, winterAltered,
    springAltered, summerAltered, fallAltered;

// Gaussian values (mean, variance) for age of analysis
float normalAgeMean, alteredAgeMean, normalAgeVariance, alteredAgeVariance;

// Probabilities for childish disease
float haveChildDiseaseNormal, noChildDiseaseNormal, haveChildDiseaseAltered,
    noChildDiseaseAltered;

// Probabilities for accident or serious trauma
float haveTraumaNormal, noTraumaNormal, haveTraumaAltered, noTraumaAltered;

// Probabilities for Surgical Intervention
float haveSurgeryNormal, noSurgeryNormal, haveSurgeryAltered, noSurgeryAltered;

// Probabilities for high fevers in last year
float haveFeverLess3MthsNormal, haveFeverMore3MthsNormal, noFeverNormal,
    haveFeverLess3MthsAltered, haveFeverMore3MthsAltered, noFeverAltered;

// Probabilities for frequency of alcohol consumption
float drinkServeralADayNormal, drinkADayNormal, drinkServeralAWeekNormal,
    drinkAWeekNormal, drinkHardlyNormal, drinkServeralADayAltered, drinkADayAltered,
    drinkServeralAWeekAltered, drinkAWeekAltered, drinkHardlyAltered;

// Probabilities for frequency of smoking habit
float neverSmokeNormal, occasionSmokeNormal, dailySmokeNormal,
    neverSmokeAltered, occasionSmokeAltered, dailySmokeAltered;

// Gaussian values (mean, variance) for number of hours spent sitting per day
float normalHrsMean, alteredHrsMean, normalHrsVariance, alteredHrsVariance;
