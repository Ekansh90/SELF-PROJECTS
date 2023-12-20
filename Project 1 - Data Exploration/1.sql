--SELECT * 
--FROM [SQL 1]..CovidDeaths 
--ORDER BY 3,4 

--SELECT * 
--FROM [SQL 1].dbo.CovidVaccinations
--ORDER BY 3,4

-- .dbo.Table name ( IS SAME AS ) ..(TABLE_NAME)


-- SELECT DATA THAT WE ARE USING 
SELECT location,DATE,total_cases,new_cases,total_deaths,population
FROM [SQL 1]..CovidDeaths 
ORDER BY 1,2

-- Looking At Total Cases vs Total Deaths (TRYING TO LOOK IN "UNITED STATES" using the LIKE KEYWORD)
SELECT location,date,total_cases,total_deaths,ROUND((total_deaths/total_cases*100),1) AS PERCENTAGE_DEATHS_PER_CASES
FROM [SQL 1]..CovidDeaths 
WHERE LOCATION LIKE '%states%'
ORDER BY 1,2


-- Look at total_cases vs populdation
SELECT location,date,population,total_cases,ROUND((total_deaths/total_cases*100),1) AS PERCENTAGE_DEATHS_PER_CASES
FROM [SQL 1]..CovidDeaths 
WHERE LOCATION LIKE '%india%'
ORDER BY 1,2
