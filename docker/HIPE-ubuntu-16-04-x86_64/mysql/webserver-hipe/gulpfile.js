var gulp = require("gulp");
var less = require('gulp-less');
var sass = require('gulp-sass');
var path = require('path');

gulp.task("css", function() {
    gulp.src([
        "./css/*.css",
        "./node_modules/fastselect/dist/fastselect.css",
        "./node_modules/cytoscape-panzoom/cytoscape.js-panzoom.css",
        "./node_modules/bootstrap/dist/css/bootstrap.min.css"
    ])
    .pipe(gulp.dest("./dist/css/"));

});

gulp.task('sass', function () {
    return gulp.src('./css/*.scss')
        .pipe(sass().on('error', sass.logError))
        .pipe(gulp.dest('./dist/css/'));
});

gulp.task("js", function() {
    gulp.src([
        "./js/*.js",
        "./node_modules/jquery/dist/jquery.js",
        //"./node_modules/jquery-ui/lodash.js",
        "./node_modules/mermaid/dist/mermaid.js",
        "./node_modules/cytoscape/dist/cytoscape.js",
        "./node_modules/dagre/dist/dagre.js",
        "./node_modules/cytoscape-dagre/cytoscape-dagre.js",
        "./node_modules/bootstrap/dist/js/bootstrap.js",
        "./node_modules/bootstrap-notify/bootstrap-notify.js",
        "./node_modules/cytoscape-edgehandles/cytoscape-edgehandles.js",
        "./node_modules/cytoscape-panzoom/cytoscape-panzoom.js",
        "./node_modules/lodash/lodash.js"
    ])
        .pipe(gulp.dest("./dist/js/"));
});

gulp.task("html", function(){
    gulp.src([
        "./views/*.ejs"
    ])
        .pipe(gulp.dest("./views/"));
})

gulp.task("fonts", function(){
    gulp.src([
        "./fonts/*.*"
    ])
        .pipe(gulp.dest("./dist/fonts/"));
})

gulp.task('watch', function() {
    // javascript changes
    gulp.watch('./js/*', ['js']);

    // css changes
    gulp.watch('./css/*', ['css', 'sass']);

    gulp.watch('./*', ['css', 'js']);

    gulp.watch('./views/*', ['html']);

});