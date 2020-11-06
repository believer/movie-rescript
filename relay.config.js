module.exports = {
  src: "./src",
  schema: "./schema.graphql",
  artifactDirectory: "./src/__generated__",
  customScalars: {
    job: "Job",
    timestamp: "string",
    date: "string",
  },
};
